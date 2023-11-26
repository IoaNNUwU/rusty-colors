# Rusty Colors

VSCode theme consisting of calming soft colors. Main colors are inspired by Rusty Copper environments and include `Light Brown`, `Soft Red`, `Rusty Blue`, `Light Gray`.

> This theme is a perfect fit for Rust language.

- Includes semantic highlighting & full support for `Rust`, `C++`, `JavaScript`, `TypeScript` and other languages listed below.
- Includes 1 `Dark` & 1 `Light` theme.

![Preview](https://raw.githubusercontent.com/IoaNNUwU/rusty-colors/master/img/Example.png)

Each language in this list has hand-crafted, fine-tuned support. Each language uses same colors for same things (functions, structs, keywords, etc. each have same color in each language).
- Rust
- C++
- JavaScript, TypeScript
- JSON, TOML, HTML, MARKDOWN, XML

## Customization

If you are using VSCode 1.12+ versions you can customize the colors to your liking, overriding the ones provided by this theme.

To do so, open command palette and type `Open User Settings (JSON)`. In this file you can override colors of this theme by adding this at the end of your settings object:

```js
// file: settings.json
{
    // your settings

    "editor.tokenColorCustomizations": {
        "[Rusty Colors]": {
            "textMateRules": [
                // put textMateRules here, for example:
                {
                    "scope": "string.quoted",
                    "settings": { "foreground": "#5fc26e" }
                }
            ]
        }
    }
}
```

Some useful textMateRules overrides you might like:
```js
// Make Strings green like comments (default strings are brown):
{
    "scope": "string.quoted",
    "settings": { "foreground": "#5fc26e" }
}

// Make all punktuation & parenthesis bras
{ 
    "scope": [ 
        "punctuation.brackets.round", "punctuation", 
        "punctuation.brackets.angle", "punctuation.brackets.curly"
    ], 
    "settings": { "foreground": "#d9a958" }
}
```

More info [here](https://code.visualstudio.com/docs/getstarted/theme-color-reference).



## Credits

- [One Dark](https://github.com/akamud/vscode-theme-onedark) - UI Colors

## Support

You can request color tweaks at [GitHub](https://github.com/IoaNNUwU/rusty-colors.git). If you want to support another language using existing colors & templates from this theme, you can do it by submitting a PR. If the color is missing, you can discover what token it is by using `Developer: Inspect Editor Tokens and Scopes` and adding this token scope in PR at GitHub.
