

# API_USAGE



```lua

  local NosyBear = require("NosyBear.NosyBear")

  params_peek = {
    URL="",
    PARAMS={KEY=VALUE, ...},
    HEADERS={KEY=VALUE, ...},
    COOKIES={KEY=VALUE, ...},
    AUTH={KEY=VALUE, ...},
    TIMEOUT=SECONDS_INTEGER,
    ALLOW_REDIRECTS=BOOLEAN,
    PROXIES={KEY=VALUE, ...},
    VERIFY=BOOLEAN,
    STREAM=BOOLEAN,
    CERT={PATH, PATH, ...}
  }

  response = NosyBear.get(params_peek)

  ---@type string
  local url_response response.url
  ---@type 
  local body = response.body
  local type_body = response.type_body
  local cookies = response.cookies
  local headers = response.headers
  local status_code = response.status_code

```







