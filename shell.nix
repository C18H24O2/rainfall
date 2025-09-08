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
    clang-tools
    python312
    efm-langserver
  ];

  buildInputs = [
    (pkgs.writeScriptBin "nuke-amd-kvm" ''
      #!${pkgs.stdenv.shell}
      set -euo pipefail
      sudo rmmod kvm-amd
      sudo rmmod kvm
    '')
  ];
}
