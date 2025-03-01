

---@return boolean
function Get_args()

  local exist_args = false
  for _, obj in ipairs(arguments) do
    if darwin.argv.one_of_args_exist(obj.arg) then
      print("\t" .. obj.arg .. "\n")
      exist_args = true
      obj.func()
    end
  end

  print("")

  return exist_args

end



