#!/usr/bin/env bash

. $(dirname $0)/common.sh

echo "Running VM"
qemu-system-x86_64 \
    -m 2G \
    -cdrom "$ISO" \
    -enable-kvm \
    -cpu host \
	-netdev user,id=net0,hostfwd=tcp::2222-:4242 \
    -device e1000,netdev=net0 \
    -smp 4
