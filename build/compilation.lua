


local function Preparation(cc, main, flags, path_out, name_out)
  darwin.dtw.remove_any(path_out)
  local path_out = path_out .. "/"
  darwin.dtw.write_file(path_out .. "cache", "")
  darwin.dtw.remove_any(path_out .. "cache")

  local result = os.execute(cc .. ' ' .. flags .. " -o " .. path_out .. name_out .. " src/" .. main)

  if not result then
    os.exit(1)
  end

  print("\n\tCompiled the" .. name_out .. " in " .. path_out .. "\n")
end

function Comp_testing()
  Preparation("gcc", "testing.c ", "", "test/c", "test.out")
  os.execute("test/c/test.out > test/c/teste.txt")
end

function Comp()
  local raw_types_temp = darwin.dtw.load_file("realeses/NosyBear/NosyBear.lua")
  Preparation("gcc", "main.c", "-shared -fpic", "realeses/NosyBear", "NosyBear.so")
  if raw_types_temp then
    darwin.dtw.write_file("realeses/NosyBear/NosyBear.lua", raw_types_temp)
  end

  darwin.dtw.remove_any("realeses/NosyBear.zip")
  os.execute("zip -r realeses/NosyBear.zip realeses/NosyBear")
end



