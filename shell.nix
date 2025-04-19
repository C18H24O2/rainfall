{
  pkgs ? import <nixpkgs> {},
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    ropgadget
    radare2
    radare2-cutter
    nmap
    qemu
    ghidra-bin
    gdb
  ];
}
