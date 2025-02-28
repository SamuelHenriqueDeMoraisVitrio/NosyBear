

local arguments = {
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

---@return boolean
function Get_args()

  local exist_args = false
  for _, obj in ipairs(arguments) do
    if darwin.argv.one_of_args_exist(obj.arg) then
      print(obj.arg)
      exist_args = true
      print(type(obj.func))
    end
  end

  return exist_args

end



