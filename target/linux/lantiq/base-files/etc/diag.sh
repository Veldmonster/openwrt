#!/bin/sh
# Copyright (C) 2010-2015 OpenWrt.org

. /lib/functions/leds.sh
. /lib/functions/lantiq.sh

<<<<<<< HEAD
status_led=power
[ ! -d /sys/class/leds/power/ ] && [ ! -d /sys/class/leds/power1/ ] && [ ! -d /sys/class/leds/power2/ ] && [ -d /sys/class/leds/wps/ ] && status_led=wps

set_state() {
	case "$1" in
	preinit)
		if [ -d /sys/class/leds/power2/ ]; then
			status_led_on
			status_led=power2
			status_led_blink_preinit
			status_led=power
		else
			status_led_blink_preinit
		fi
		;;
	failsafe)
		if [ -d /sys/class/leds/power2/ ]; then
			led_off power2
			status_led_blink_failsafe
		elif [ -d /sys/class/leds/power1/ ]; then
			status_led_off
			status_led=power1
			status_led_blink_failsafe
			status_led=power
		else
			status_led_blink_failsafe
		fi
		;;
	preinit_regular)
		if [ -d /sys/class/leds/power2/ ]; then
			status_led_on
			status_led=power2
			status_led_blink_preinit_regular
			status_led=power
		else
			status_led_blink_preinit_regular
		fi
		;;
	done)
		status_led_on
		led_off power1
		led_off power2
=======
boot="$(lantiq_get_dt_led_chosen boot)"
failsafe="$(lantiq_get_dt_led_chosen failsafe)"
running="$(lantiq_get_dt_led_chosen running)"

set_state() {
    status_led="$boot"

	case "$1" in
	preinit)
		status_led_blink_preinit
		;;
	failsafe)
		status_led_off
		status_led="$failsafe"
		status_led_blink_failsafe
		;;
	preinit_regular)
		status_led_blink_preinit_regular
		;;
	done)
		status_led_off
		[ -n "$running" ] && {
			status_led="$running"
			status_led_on
		}
>>>>>>> 871372c42a3fc9c4b33f5c6011742d610a2e5600
		;;
	esac
}
