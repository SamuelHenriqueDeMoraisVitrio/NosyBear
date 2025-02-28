

BUILD = darwin.candango.Get_text_by_file_content("doc/build.md")
API_USAGE = darwin.candango.Get_text_by_file_content("doc/api_usage.md")

Update_doc = function ()

  local readme = darwin.candango.Render_text(darwin.dtw.load_file("doc/main.md"))

  if readme.exist_error then
    print("\n\tERROR candango is: ", readme.error_message)
    os.exit(1)
  end

  print("\n\tREADME renderized")
  darwin.dtw.write_file("README.md", readme.render_text)

end
