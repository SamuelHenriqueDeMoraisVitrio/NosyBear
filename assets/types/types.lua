
---@class Response
---@field body { content: string|any|nil, size: integer }
---@field headers (table<string, string> | { key: string, value: string })[]
---@field status_code integer
---@field error { exist: boolean, message: string }

---@class ParamsPeek
---@field URL string
---@field HEADERS table<string, string>
---@field MAX_ALLOW_REDIRECTS integer
---@field METHOD string
---@field MAX_DOWNLOAD_SIZE integer
---@field UPLOAD_PATH string
---@field UPLOAD_ANY { content: string|table, size: string|nil|0 }

---@class NosyBear
---@field peek fun(params:ParamsPeek): Response

