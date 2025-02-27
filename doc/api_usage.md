

# API_USAGE

## Dependencie
To include in your project:
```lua
  local NosyBear = require("NosyBear.NosyBear")
```
---
## Request
To request a link
```lua
  params_peek = {
    URL="",
    PARAMS={KEY=VALUE, ...},
    HEADERS={KEY=VALUE, ...},
    COOKIES={KEY=VALUE, ...},
    MAX_ALLOW_REDIRECTS=INTEGER,
    METHOD=STRING_OF_METHOD,
    MAX_DOWNLOAD_SIZE=INTEGER,
    UPLOAD_PATH=STRING,
    UPLOAD_ANY=STRING_TABLE
  }

  local response = NosyBear.peek(params_peek)
```

| PARAM               | Types Value               | Examplo                                                | DEFAULT     | Explain                     |
--------------------------------------------------------------------------------------------------------------------------------------------------------
| URL                 | Table                     | {"Key"="Value"}                                        | Mandatory   | URL to feth                 |
| PARAMS              | Table                     | {"Key"="Value"}                                        | nil         | Params to be passed         |
| HEADER              | Table                     | {"Key"="Value"}                                        | nil         | Headers to be passed        |
| COOKIES             | Table                     | {"Key"="Value"}                                        | nil         | Cookies to be passed        |
| MAX_ALLOW_REDIRECTS | Boolean                   | 0                                                      | ()          | Maximum redirects           |
| METHOD              | String                    | "GET"                                                  | "GET"       | Method of request           |
| MAX_DOWNLOAD_SIZE   | Integer                   | 1000                                                   | ()          | Download space limit        |
| UPLOAD_PATH         | String                    | "/home/Documents/juninho_trevozo.txt"                  | Dont upload | File path to pass to body   |
| UPLOAD_ANY          | String or table(for:json) | "Binary string" ou {name="juninho", nikname="Trevoso"} | Dont upload | Binary or json to pass body |


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

  response = NosyBear.peek(params_peek)

  ---@type string
  local url_response response.url
  ---@type 
  local body = response.body
  local type_body = response.type_body
  local cookies = response.cookies
  local headers = response.headers
  local status_code = response.status_code

```







