{
  description = "A C++ development environment for AtCoder with ac-library";

  # Define the inputs for your flake
  inputs = {
    # The standard Nix packages collection
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

    # A helper for creating multi-system flakes easily
    flake-utils.url = "github:numtide/flake-utils";

    # The AtCoder Library source code
    ac-library = {
      url = "github:atcoder/ac-library/864245a00b00dd008d1abfdc239618fdb7d139da";
      flake = false;
    };
  };

  # Define the outputs of your flake
  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      ac-library,
      ...
    }:
    # Use flake-utils to generate outputs for common systems
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        # Get the packages for the current system
        pkgs = nixpkgs.legacyPackages.${system};

        # 1. Define the ac-library package
        # Since it's header-only, we just need to copy the files.
        acl = pkgs.stdenv.mkDerivation {
          pname = "ac-library";
          version = "latest";

          # Use the source code from the flake input
          src = ac-library;

          # The "build" is just an install phase
          installPhase = ''
            # Create the include directory
            mkdir -p $out/include

            # Copy the 'atcoder' folder into it
            # So you get $out/include/atcoder/dsu.hpp, etc.
            cp -r atcoder $out/include/
          '';
        };

      in
      {
        # 2. Define the development shell
        devShells.default = pkgs.mkShell {

          # Add your C++ compiler and our new 'acl' package
          buildInputs = [
            pkgs.libgcc # For C++ standard library support
            pkgs.gdb # The GDB debugger
            acl # Our AtCoder Library package
          ];

          # 3. Tell the compiler where to find the headers
          shellHook = ''
            # This environment variable tells g++ where to look for includes
            export CPLUS_INCLUDE_PATH="${acl}/include:$CPLUS_INCLUDE_PATH"

            echo "✅ C++ environment with AtCoder Library is ready."
            echo "Compiler: g++ (v$(g++ -dumpversion))"
          '';
        };
      }
    );
}
