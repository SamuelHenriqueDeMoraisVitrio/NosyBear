
---@type Darwin
darwin = darwin



function main()

  arguments = {
    {
      arg="help",
      func=Help
    },
    {
      arg="silver",
      func=Initialize_silver
    },
    {
      arg="dependencies",
      func=Install_dependencies
    },
    {
      arg="document",
      func=Update_doc
    },
    {
      arg="comp_testing",
      func=Comp_testing
    },
    {
      arg="comp",
      func=Comp
    }
  }

  if not Get_args() then

    Install_dependencies()

    Initialize_silver()

    Update_doc()

    Comp_testing()

    Comp()

  end

  print("\tEND\n\n")

end



