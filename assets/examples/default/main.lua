
local NosyBear = require("realeses/NosyBear/NosyBear")



local params = {
  URL="https://www.google.com",
  HEADERS={key1="value"}
}

local response = NosyBear.peek(params)
response = ""

print("\n\tresponse:\n", response, "\n\t:Response;")



