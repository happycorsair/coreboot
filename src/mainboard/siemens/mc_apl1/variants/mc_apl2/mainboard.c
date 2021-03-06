/* SPDX-License-Identifier: GPL-2.0-only */

#include <bootstate.h>
#include <console/console.h>
#include <device/pci_def.h>
#include <device/pci_ids.h>
#include <device/pci_ops.h>
#include <hwilib.h>
#include <intelblocks/lpc_lib.h>
#include <baseboard/variants.h>
#include <soc/pci_devs.h>
#include <types.h>

void variant_mainboard_final(void)
{
	struct device *dev;

	/* Set Master Enable for on-board PCI device. */
	dev = dev_find_device(PCI_VENDOR_ID_SIEMENS, 0x403e, 0);
	if (dev) {
		pci_or_config16(dev, PCI_COMMAND, PCI_COMMAND_MASTER);
	}
}
