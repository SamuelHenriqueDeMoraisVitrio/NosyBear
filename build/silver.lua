

Initialize_silver = function ()
  
  darwin.silverchain.generate({
      src = "src",
      tags = { "dep", "mac", "types", "global", "dec", "def" },
      project_short_cut = "NosyBear"
  })

  print("\tFinalized SilverChain.\n")

end
