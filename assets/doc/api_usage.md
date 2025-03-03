
---

## API_USAGE

### Dependencie
To include in your project:
```lua
  local NosyBear = require("NosyBear.NosyBear")
```
---

### Request
To request a link
```lua
  params_peek = {
    URL="",
    HEADERS={KEY=VALUE, ...},
    MAX_ALLOW_REDIRECTS=INTEGER,
    METHOD=STRING_OF_METHOD,
    MAX_DOWNLOAD_SIZE=INTEGER,
    UPLOAD_PATH=STRING,
    UPLOAD_ANY=STRING_TABLE
  }

  local response = NosyBear.peek(params_peek)

```

| PARAM               | Types Value               | Examplo                                                | DEFAULT      | Explain                     |
|---------------------|---------------------------|--------------------------------------------------------|--------------|-----------------------------|
| URL                 | Table                     | {"Key"="Value"}                                        | Mandatory    | URL to feth                 |
| PARAMS              | Table                     | {"Key"="Value"}                                        | nil          | Params to be passed         |
| HEADER              | Table                     | {"Key"="Value"}                                        | nil          | Headers to be passed        |
| COOKIES             | Table                     | {"Key"="Value"}                                        | nil          | Cookies to be passed        |
| MAX_ALLOW_REDIRECTS | Boolean                   | 0                                                      | ()           | Maximum redirects           |
| METHOD              | String                    | "GET"                                                  | "GET"        | Method of request           |
| MAX_DOWNLOAD_SIZE   | Integer                   | 1000                                                   | ()           | Download space limit        |
| UPLOAD_PATH         | String                    | "/home/Documents/juninho_trevozo.txt"                  | Dont upload  | File path to pass to body   |
| UPLOAD_ANY          | String or table(for:json) | "Binary string" or {name="juninho", nikname="Trevoso"} | Dont upload  | Binary or json to pass body |
| UPLOAD_CONTENT_TYPE | String                    | "text/plain"                                           | "text/plain" | Past content type.          |

---

### Response
The request response
```lua
  ...

  local response = NosyBear.peek(params_peek)
  
  ---@type string
  local url_response = response.url
  ---@type string|any|nil
  local body = response.body.content
  ---@type table|nil
  local body_json = response.body.content_json
  ---@type integer
  local body_size = response.body.size
  ---@type table
  local headers = response.headers
  ---@type integer
  local status_code = response.status_code
  ---@type Boolean
  local requisition_error = response.error.exist
  ---@type string
  local requisition_error_message = response.error.message

  if requisition_error.exist then
    print(requisition_error.message)
    return
  end

  print(url_response)

  if type_body == "str" then
    print(body)
  end
  if type_body == "table" then
    print("Is a json type")
  end
  if type_body == "bin" then
    print("Is a binary type")
  end
  if type_body == nil then
    print("Is dont a body")
  end

  for i=1, #cookies do
    print("KEY: " .. cookies[i].key)
    print("VALUE: " .. cookies[i].value)
  end

  for i=1, #headers do
    print("KEY: ", headers[i].key)
    print("VALUE: ", headers[i].value)
  end

  print(status_code)
```

---


