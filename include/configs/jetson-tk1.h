/*
 * (C) Copyright 2013-2014
 * NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:     GPL-2.0
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

/* enable PMIC */
#define CONFIG_AS3722_POWER

/* LP0 suspend / resume */
#define CONFIG_TEGRA_LP0
#define CONFIG_AES

#include "tegra124-common.h"

#ifndef CONFIG_SPL_BUILD
#define CONFIG_OF_LIBFDT
#define CONFIG_OF_BOARD_SETUP
#define CONFIG_SERIAL_TAG
#define CONFIG_TEGRA_SERIAL_HIGH	0x01770000
#define CONFIG_TEGRA_SERIAL_LOW		0x034200FF
#define CONFIG_OF_REMOVE_FIRMWARE_NODES

/* The following are used to retrieve the board id from an eeprom */
#define CONFIG_SERIAL_EEPROM
#define EEPROM_I2C_BUS         1
#define EEPROM_I2C_ADDRESS     0x56
#define EEPROM_SERIAL_OFFSET   0x04
#define NUM_SERIAL_ID_BYTES    8

#ifdef CONFIG_TEGRA_LP0
#define CONFIG_TEGRA124_LP0
#endif

#define CONFIG_OF_LIBFDT
#define CONFIG_OF_BOARD_SETUP

#define CONFIG_SERIAL_TAG

/* The following are used to retrieve the board id from an eeprom */
#define CONFIG_SERIAL_EEPROM
#define EEPROM_I2C_BUS         1
#define EEPROM_I2C_ADDRESS     0x56
#define EEPROM_SERIAL_OFFSET   0x04
#define NUM_SERIAL_ID_BYTES    8

/* High-level configuration options */
#define CONFIG_SYS_PROMPT		"Tegra124 (Jetson TK1) # "
#define CONFIG_TEGRA_BOARD_STRING	"NVIDIA Jetson TK1"

/* Board-specific serial config */
#define CONFIG_TEGRA_ENABLE_UARTD
#define CONFIG_SYS_NS16550_COM1		NV_PA_APB_UARTD_BASE

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT

/* I2C */
#define CONFIG_SYS_I2C_TEGRA
#define CONFIG_CMD_I2C

/* SD/MMC */
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_TEGRA_MMC
#define CONFIG_CMD_MMC

/* Environment in eMMC, at the end of 2nd "boot sector" */
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_ENV_OFFSET		(-CONFIG_ENV_SIZE)
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_SYS_MMC_ENV_PART		2

/* SPI */
#define CONFIG_TEGRA114_SPI		/* Compatible w/ Tegra114 SPI */
#define CONFIG_TEGRA114_SPI_CTRLS	6
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_WINBOND
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#define CONFIG_SF_DEFAULT_SPEED		24000000
#define CONFIG_CMD_SPI
#define CONFIG_CMD_SF
#define CONFIG_SPI_FLASH_SIZE		(4 << 20)

/* USB Host support */
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_TEGRA
#define CONFIG_USB_MAX_CONTROLLER_COUNT	2
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_USB

/* USB networking support */
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX

/* PCI host support */
#define CONFIG_PCI
#define CONFIG_PCI_TEGRA
#define CONFIG_PCI_PNP
#define CONFIG_CMD_PCI
#define CONFIG_CMD_PCI_ENUM

/* PCI networking support */
#define CONFIG_RTL8169

/* General networking support */
#define CONFIG_CMD_DHCP

#include "tegra-common-usb-gadget.h"
#include "tegra-common-post.h"

#if 0 /* L4T compiler workaround */
#define CONFIG_ARMV7_PSCI			1
/* Reserve top 1M for secure RAM */
#define CONFIG_ARMV7_SECURE_BASE		0xfff00000
#define CONFIG_ARMV7_SECURE_RESERVE_SIZE	0x00100000
#endif

#endif /* __CONFIG_H */
