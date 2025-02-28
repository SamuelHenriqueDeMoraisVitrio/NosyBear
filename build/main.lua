
---@type Darwin
darwin = darwin

function main()

  if not Get_args() then

    Install_dependencies()

    Initialize_silver()

    Update_doc()

  end

  print("\tEND\n\n")

end



