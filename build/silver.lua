

function Initialize_silver()
  
  darwin.silverchain.generate({
      src = "src",
      tags = { "dep", "mac", "types", "const", "dec", "def" },
      project_short_cut = "NosyBear"
  })

  print("\tFinalized SilverChain.\n")

end
