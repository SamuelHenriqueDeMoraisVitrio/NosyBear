
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

Then, run the following command:
- For Local execution: **./darwin**
- For Global execution: **darwin**

```bash
darwin run_blueprint build -mode folder
```

The final binary will be located in the releases folder.


