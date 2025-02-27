
---@type Darwin
darwin = darwin

function main()

  local project = darwin.create_project("NosyBear")

  Install_dependencies()

  Initialize_silver()

  Update_doc()

  print("\tEND\n\n")

end



