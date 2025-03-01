
---@type Darwin
darwin = darwin



function main()

  arguments = {
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
  }

  if not Get_args() then

    Install_dependencies()

    Initialize_silver()

    Update_doc()

  end

  print("\tEND\n\n")

end



