/**
 * 
 * Ulfius Framework example program
 * 
 * This example program describes the main features 
 * that are available in a callback function
 * 
 * Copyright 2015 Nicolas Mora <mail@babelouest.org>
 * 
 * License MIT
 *
 */

#include <string.h>
#include <jansson.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../../src/ulfius.h"

#define PORT 8537
#define PREFIX "/test"
#define PREFIXJSON "/testjson"
#define PREFIXCOOKIE "/testcookie"

/**
 * callback functions declaration
 */
int callback_get_test (const struct _u_request * request, struct _u_response * response, void * user_data);

int callback_get_empty_response (const struct _u_request * request, struct _u_response * response, void * user_data);

int callback_post_test (const struct _u_request * request, struct _u_response * response, void * user_data);

int callback_all_test_foo (const struct _u_request * request, struct _u_response * response, void * user_data);

int callback_put_jsontest (const struct _u_request * request, struct _u_response * response, void * user_data);

int callback_get_cookietest (const struct _u_request * request, struct _u_response * response, void * user_data);

int callback_default (const struct _u_request * request, struct _u_response * response, void * user_data);

/**
 * decode a u_map into a string
 */
char * print_map(const struct _u_map * map) {
  char * line, * to_return = NULL;
  const char **keys, * value;
  int len, i;
  if (map != NULL) {
    keys = u_map_enum_keys(map);
    for (i=0; keys[i] != NULL; i++) {
      value = u_map_get(map, keys[i]);
      len = snprintf(NULL, 0, "key is %s, value is %s", keys[i], value);
      line = malloc((len+1)*sizeof(char));
      snprintf(line, (len+1), "key is %s, value is %s", keys[i], value);
      if (to_return != NULL) {
        len = strlen(to_return) + strlen(line) + 1;
        to_return = realloc(to_return, (len+1)*sizeof(char));
        if (strlen(to_return) > 0) {
          strcat(to_return, "\n");
        }
      } else {
                to_return = malloc((strlen(line) + 1)*sizeof(char));
                to_return[0] = 0;
      }
      strcat(to_return, line);
      free(line);
    }
    return to_return;
  } else {
    return NULL;
  }
}

char * read_file(const char * filename) {
  char * buffer = NULL;
  long length;
  FILE * f = fopen (filename, "rb");
  if (filename != NULL) {

    if (f) {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = malloc (length + 1);
      if (buffer) {
        fread (buffer, 1, length, f);
      }
      buffer[length] = '\0';
      fclose (f);
    }
    return buffer;
  } else {
    return NULL;
  }
}

int main (int argc, char **argv) {
  int ret;
  
  // Set the framework port number
  struct _u_instance instance;
  
  y_init_logs("simple_example", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "Starting simple_example");
  
  if (ulfius_init_instance(&instance, PORT, NULL) != U_OK) {
    y_log_message(Y_LOG_LEVEL_ERROR, "Error ulfius_init_instance, abort");
    return(1);
  }
  
  u_map_put(instance.default_headers, "Access-Control-Allow-Origin", "*");
  
  // Maximum body size sent by the client is 1 Kb
  instance.max_post_body_size = 1024;
  
  // Endpoint list declaration
  ulfius_add_endpoint_by_val(&instance, "GET", PREFIX, NULL, NULL, NULL, NULL, &callback_get_test, NULL);
  ulfius_add_endpoint_by_val(&instance, "GET", PREFIX, "/empty", NULL, NULL, NULL, &callback_get_empty_response, NULL);
  ulfius_add_endpoint_by_val(&instance, "GET", PREFIX, "/multiple/:multiple/:multiple/:not_multiple", NULL, NULL, NULL, &callback_all_test_foo, NULL);
  ulfius_add_endpoint_by_val(&instance, "POST", PREFIX, NULL, NULL, NULL, NULL, &callback_post_test, NULL);
  ulfius_add_endpoint_by_val(&instance, "GET", PREFIX, "/:foo", NULL, NULL, NULL, &callback_all_test_foo, "user data 1");
  ulfius_add_endpoint_by_val(&instance, "POST", PREFIX, "/:foo", NULL, NULL, NULL, &callback_all_test_foo, "user data 2");
  ulfius_add_endpoint_by_val(&instance, "PUT", PREFIX, "/:foo", NULL, NULL, NULL, &callback_all_test_foo, "user data 3");
  ulfius_add_endpoint_by_val(&instance, "DELETE", PREFIX, "/:foo", NULL, NULL, NULL, &callback_all_test_foo, "user data 4");
  ulfius_add_endpoint_by_val(&instance, "PUT", PREFIXJSON, NULL, NULL, NULL, NULL, &callback_put_jsontest, NULL);
  ulfius_add_endpoint_by_val(&instance, "GET", PREFIXCOOKIE, "/:lang/:extra", NULL, NULL, NULL, &callback_get_cookietest, NULL);
  
  // default_endpoint declaration
  ulfius_set_default_endpoint(&instance, NULL, NULL, NULL, &callback_default, NULL);
  
  // Start the framework
  if (argc == 4 && strcmp("-secure", argv[1]) == 0) {
    // If command-line options are -secure <key_file> <cert_file>, then open an https connection
    char * key_pem = read_file(argv[2]), * cert_pem = read_file(argv[3]);
    ret = ulfius_start_secure_framework(&instance, key_pem, cert_pem);
    free(key_pem);
    free(cert_pem);
  } else {
    // Open an http connection
    ret = ulfius_start_framework(&instance);
  }
  
  if (ret == U_OK) {
    y_log_message(Y_LOG_LEVEL_DEBUG, "Start %sframework on port %d", ((argc == 4 && strcmp("-secure", argv[1]) == 0)?"secure ":""), instance.port);
    
    // Wait for the user to press <enter> on the console to quit the application
    getchar();
  } else {
    y_log_message(Y_LOG_LEVEL_DEBUG, "Error starting framework");
  }
  y_log_message(Y_LOG_LEVEL_DEBUG, "End framework");
  
  y_close_logs();
  
  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);
  
  return 0;
}

/**
 * Callback function that put a "Hello World!" string in the response
 */
int callback_get_test (const struct _u_request * request, struct _u_response * response, void * user_data) {
  response->string_body = strdup("Hello World!");
  response->status = 200;
  return U_OK;
}

/**
 * Callback function that put an empty response and a status 200
 */
int callback_get_empty_response (const struct _u_request * request, struct _u_response * response, void * user_data) {
  return U_OK;
}

/**
 * Callback function that put a "Hello World!" and the post parameters send by the client in the response
 */
int callback_post_test (const struct _u_request * request, struct _u_response * response, void * user_data) {
  int len;
  char * post_params = print_map(request->map_post_body);
  len = snprintf(NULL, 0, "Hello World!\n%s", post_params);
  response->string_body = malloc((len+1)*sizeof(char));
  snprintf(response->string_body, (len+1), "Hello World!\n%s", post_params);
  free(post_params);
  response->status = 200;
  return U_OK;
}

/**
 * Callback function that put "Hello World!" and all the data sent by the client in the response as string (http method, url, params, cookies, headers, post, json, and user specific data in the response
 */
int callback_all_test_foo (const struct _u_request * request, struct _u_response * response, void * user_data) {
  char * url_params = print_map(request->map_url), * headers = print_map(request->map_header), * cookies = print_map(request->map_cookie), 
        * post_params = print_map(request->map_post_body), * json_params = json_dumps(request->json_body, JSON_INDENT(2));
  int len;
  len = snprintf(NULL, 0, "Hello World!\n\n  method is %s\n  url is %s\n\n  parameters from the url are \n%s\n\n  cookies are \n%s\n\n  headers are \n%s\n\n  post parameters are \n%s\n\n  json body parameters are \n%s\n\n  user data is %s\n\nclient address is %s\n\n",
                                  request->http_verb, request->http_url, url_params, cookies, headers, post_params, json_params, (char *)user_data, inet_ntoa(((struct sockaddr_in *)request->client_address)->sin_addr));
  response->string_body = malloc((len+1)*sizeof(char));
  snprintf(response->string_body, (len+1), "Hello World!\n\n  method is %s\n  url is %s\n\n  parameters from the url are \n%s\n\n  cookies are \n%s\n\n  headers are \n%s\n\n  post parameters are \n%s\n\n  json body parameters are \n%s\n\n  user data is %s\n\nclient address is %s\n\n",
                                  request->http_verb, request->http_url, url_params, cookies, headers, post_params, json_params, (char *)user_data, inet_ntoa(((struct sockaddr_in *)request->client_address)->sin_addr));
  response->status = 200;
  
  free(url_params);
  free(headers);
  free(cookies);
  free(post_params);
  free(json_params);
  return U_OK;
}

/**
 * Callback function that put "Hello World!", the http method and the url in a json response
 */
int callback_put_jsontest (const struct _u_request * request, struct _u_response * response, void * user_data) {
  response->json_body = json_object();
  json_object_set_new(response->json_body, "message", json_string("Hello World!"));
  json_object_set_new(response->json_body, "method", json_string(request->http_verb));
  json_object_set_new(response->json_body, "url", json_string(request->http_url));
  if (!request->json_error) {
    json_object_set(response->json_body, "request", request->json_body);
  } else {
    json_object_set_new(response->json_body, "request", json_pack("{ssss}", "title", "Error parsing request", "message", request->json_error->text));
  }
  response->status = 200;
  return U_OK;
}

/**
 * Callback function that sets cookies in the response
 * The counter cookie is incremented every time the client reloads this url
 */
int callback_get_cookietest (const struct _u_request * request, struct _u_response * response, void * user_data) {
  const char * lang = u_map_get(request->map_url, "lang"), * extra = u_map_get(request->map_url, "extra"), 
             * counter = u_map_get(request->map_cookie, "counter");
  char new_counter[8];
  int i_counter;
  
  if (counter == NULL) {
    i_counter = 0;
  } else {
    i_counter = strtol(counter, NULL, 10);
    i_counter++;
  }
  snprintf(new_counter, 7, "%d", i_counter);
  ulfius_add_cookie_to_response(response, "lang", lang, NULL, 0, NULL, NULL, 0, 0);
  ulfius_add_cookie_to_response(response, "extra", extra, NULL, 0, NULL, NULL, 0, 0);
  ulfius_add_cookie_to_response(response, "counter", new_counter, NULL, 0, NULL, NULL, 0, 0);
  response->string_body = strdup("Cookies set");
  
  return U_OK;
}

/**
 * Default callback function called if no endpoint has a match
 */
int callback_default (const struct _u_request * request, struct _u_response * response, void * user_data) {
  response->string_body = strdup("Page not found, do what you want");
  response->status = 404;
  return U_OK;
}
