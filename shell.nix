{
  pkgs ? import <nixpkgs> {
    config = {
      allowUnfree = true;
      permittedInsecurePackages = [
        "python-2.7.18.8"
      ];
    };
  },
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    ropgadget
    nmap
    qemu
    ghidra-bin
    gdb
    sshpass
    python2
    python312
  ];
}
