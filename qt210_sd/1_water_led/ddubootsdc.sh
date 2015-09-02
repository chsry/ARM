#!/bin/bash

dd seek=1 if=led.bl1 of=/dev/sdb oflag=dsync
