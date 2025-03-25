{
  pkgs ? import <nixpkgs> {},
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    nmap
    qemu
    ghidra-bin
  ];
}
