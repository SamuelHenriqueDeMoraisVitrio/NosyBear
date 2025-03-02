
---@type Darwin
darwin = darwin



function main()

  arguments = {
    {
      arg="help",
      func=Help,
      description="Describes all building sectors."
    },
    {
      arg="silver",
      func=Initialize_silver,
      description="Implements the necessary imports for 'include' and 'auto complete'."
    },
    {
      arg="dependencies",
      func=Install_dependencies,
      description="Installs the necessary external dependencies."
    },
    {
      arg="document",
      func=Update_doc,
      description="Builds 'README.md' from 'doc/main.md'."
    },
    {
      arg="comp_testing",
      func=Comp_testing,
      description="Compiles test mode from 'src/testing.c' to 'test/c/teste.out' and with an output to 'test/c/teste.txt'."
    },
    {
      arg="comp",
      func=Comp,
      description="'src/main.c' is compiled to realeses."
    },
    {
      arg="types",
      func=Update_types,
      description="Update types in realeses."
    }
  }

  if not Get_args() then

    Install_dependencies()

    Initialize_silver()

    Update_doc()

    Comp_testing()

    Comp()

    Update_types()

  end

  print("\tEND\n\n")

end





