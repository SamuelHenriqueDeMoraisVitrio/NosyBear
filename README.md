# NosyBear
People love to "snoop" around, and the lib will fetch data from the web.

<details>
  <summary><h2>BUILD</h2></summary>

  
---

If you want to compile the project, you can run the following command:
```bash
sh build.sh
```

Or you can build it manually. To do this, you need to have Darwin installed on your computer or in your project. It is recommended to use version 0.19 or higher.
### Local Installation:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.out -o darwin && chmod +x darwin
```

### Global Installation:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.out -o darwin && chmod +x darwin && sudo mv darwin /usr/bin
```

### Building:

Then, run the following command:
- For Local execution: **./darwin**
- For Global execution: **darwin**

To make the complete build.
```bash
./darwin run_blueprint build -mode folder
```
The final binary will be located in the releases folder.

The build is separated into sectors such as, building README.md, compilation, ...
If you want to build a specific sector I recommend doing:
```bash
./darwin run_blueprint build -mode folder help
```
This will write all sector instructions to the screen.





</details>


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




## Simple demonstration example.



### deafault requisition

A simple standard request, passing the link and writing the response body on the screen.


```bash

local NosyBear = require("realeses/NosyBear/NosyBear")



local params = {
  URL="https://www.google.com",
  HEADERS={key1="value"}
}

local response = NosyBear.peek(params)
response = ""

print("\n\tresponse:\n", response, "\n\t:Response;")




```



