#!/bin/bash

dd seek=1 if=uart.bl1 of=/dev/sdb oflag=dsync
