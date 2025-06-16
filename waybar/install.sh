#!/bin/bash


export WAYBAR_CONF_DIR="${HOME}/.config/waybar"

if [ ! -d "${WAYBAR_CONF_DIR}" ]; then
	mkdir -pv "${WAYBAR_CONF_DIR}"
fi
if [ ! -f "${WAYBAR_CONF_DIR}/config.jsonc" ]; then
	cp waybar/config.jsonc "${WAYBAR_CONF_DIR}/config.jsonc"
fi
if [ ! -f "${WAYBAR-CONF_DIR}/style.css" ]; then
	cp waybar/style.css "${WAYBAR_CONF_DIR}/style.css"
fi
