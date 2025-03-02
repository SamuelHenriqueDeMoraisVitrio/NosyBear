
TYPES = darwin.candango.Get_text_by_file_content("assets/types/types")

function Update_types()

  local types = darwin.candango.Render_text(darwin.dtw.load_file("assets/types/main"))

  if types.exist_error then
    print("\n\tERROR candango is: ", types.error_message)
    os.exit(1)
  end

  print("\n\tTypes renderized")
  darwin.dtw.write_file("realeses/NosyBear/NosyBear.lua", types.render_text)
end
