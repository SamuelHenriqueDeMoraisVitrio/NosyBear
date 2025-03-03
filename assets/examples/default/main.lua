
local NosyBear = require("realeses/NosyBear/NosyBear")



local params = {
  URL="https://www.google.com",
  HEADERS={key1="value"}
}

local response = NosyBear.peek(params)

if response.error.exist then
  print(response.error.message)
  return
end

print(response.body.content)





