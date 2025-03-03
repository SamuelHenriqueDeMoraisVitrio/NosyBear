
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
    UPLOAD_ANY={content=STRING_OR_TABLE, size=STRING_OR_NIL_OR_0}--TABLE: Doesn't work yet
  }

  local response = NosyBear.peek(params_peek)

```

| PARAM               | Types Value                            | Examplo                                                | DEFAULT      | Explain                     |
|---------------------|----------------------------------------|--------------------------------------------------------|--------------|-----------------------------|
| URL                 | Table                                  | {"Key"="Value"}                                        | Mandatory    | URL to feth                 |
| HEADER              | Table                                  | {"Key"="Value"}                                        | nil          | Headers to be passed        |
| MAX_ALLOW_REDIRECTS | Boolean                                | 0                                                      | ()           | Maximum redirects           |
| METHOD              | String                                 | "GET"                                                  | "GET"        | Method of request           |
| MAX_DOWNLOAD_SIZE   | Integer                                | 1000                                                   | ()           | Download space limit        |
| UPLOAD_PATH         | String                                 | "/home/Documents/juninho_trevozo.txt"                  | Dont upload  | File path to pass to body   |
| UPLOAD_ANY          | {content=StringOrTable, size=intOrNil} | {content="Binary string", size=200}                    | UPLOAD_PATH  | Binary or json to pass body |

---

The 'UPLOAD_ANY' and 'UPLOAD_PATH' work differently.
- If neither of the two arguments is provided, the request will not include a body.
- The priority order is as follows:
  - If no argument is provided, no body is sent.
  - If UPLOAD_PATH is present, it will be used.
  - If only UPLOAD_ANY exists, it will be used.
In UPLOAD_ANY:
- If only 'content' is provided, it will be treated as a string.
- If 'content' is provided along with 'size', it will be considered binary.
- If 'content' is a table, it will be interpreted as JSON.


### Response
The request response
```lua
  ...

  local response = NosyBear.peek(params_peek)
  
  ---@type string|any|nil
  local body = response.body.content
  ---@type table|nil
  --local body_json = response.body.content_json
  ---@type integer
  local body_size = response.body.size
  ---@type table
  local headers = response.headers
  ---@type string
  local key1 = headers[1].key
  ---@type string
  local value1 = headers[1].value
  ---@type integer
  local status_code = response.status_code
  ---@type Boolean
  local requisition_error = response.error.exist
  ---@type string
  local requisition_error_message = response.error.message

---


