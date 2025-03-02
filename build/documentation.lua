

BUILD = darwin.candango.Get_text_by_file_content("assets/doc/build.md")
API_USAGE = darwin.candango.Get_text_by_file_content("assets/doc/api_usage.md")

function Update_doc()

  local readme = darwin.candango.Render_text(darwin.dtw.load_file("assets/doc/main.md"))

  if readme.exist_error then
    print("\n\tERROR candango is: ", readme.error_message)
    os.exit(1)
  end

  print("\n\tREADME renderized")
  darwin.dtw.write_file("README.md", readme.render_text)

end
