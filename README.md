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
|---------------------|---------------------------|--------------------------------------------------------|-------------|-----------------------------|
| URL                 | Table                     | {"Key"="Value"}                                        | Mandatory   | URL to feth                 |
| PARAMS              | Table                     | {"Key"="Value"}                                        | nil         | Params to be passed         |
| HEADER              | Table                     | {"Key"="Value"}                                        | nil         | Headers to be passed        |
| COOKIES             | Table                     | {"Key"="Value"}                                        | nil         | Cookies to be passed        |
| MAX_ALLOW_REDIRECTS | Boolean                   | 0                                                      | ()          | Maximum redirects           |
| METHOD              | String                    | "GET"                                                  | "GET"       | Method of request           |
| MAX_DOWNLOAD_SIZE   | Integer                   | 1000                                                   | ()          | Download space limit        |
| UPLOAD_PATH         | String                    | "/home/Documents/juninho_trevozo.txt"                  | Dont upload | File path to pass to body   |
| UPLOAD_ANY          | String or table(for:json) | "Binary string" or {name="juninho", nikname="Trevoso"} | Dont upload | Binary or json to pass body |

---

### Response
The request response
```lua
  ...

  local response = NosyBear.peek(params_peek)
  
  ---@type string
  local url_response = response.url
  ---@type string|table|any
  local body = response.body
  ---@type string
  local type_body = response.type_body
  ---@type table
  local cookies = response.cookies
  ---@type table
  local headers = response.headers
  ---@type integer
  local status_code = response.status_code
  ---@type Boolean
  local requisition_error = response.error

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




## Simple demonstration example.


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



