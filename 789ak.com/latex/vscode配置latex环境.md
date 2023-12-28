[Visual Studio Code (vscode)配置LaTeX - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/166523064?utm_id=0)

tex安装：[Acquiring TeX Live as an ISO image - TeX Users Group (tug.org)](https://tug.org/texlive/acquire-iso.html)



json文件：

```json
 // https://zhuanlan.zhihu.com/p/166523064?utm_id=0

        // 1. onFileChange：在检测任何依赖项中的文件更改(甚至被其他应用程序修改)时构建项目，即当检测到代码被更改时就自动编译tex文件；
        // 2. onSave : 当代码被保存时自动编译文件；
        // 3. never: 从不自动编译，即需编写者手动编译文档
        "latex-workshop.latex.autoBuild.run": "onSave",
        "latex-workshop.showContextMenu": true,
        "latex-workshop.intellisense.package.enabled": true,
        "latex-workshop.message.error.show": false,
        "latex-workshop.message.warning.show": false,
        "latex-workshop.latex.tools": [
            {
                "name": "xelatex",
                "command": "xelatex",
                "args": [
                    "-synctex=1",
                    "-interaction=nonstopmode",
                    "-file-line-error",
                    "%DOCFILE%"
                ]
            },
            {
                "name": "pdflatex",
                "command": "pdflatex",
                "args": [
                    "-synctex=1",
                    "-interaction=nonstopmode",
                    "-file-line-error",
                    "%DOCFILE%"
                ]
            },
            {
                "name": "latexmk",
                "command": "latexmk",
                "args": [
                    "-synctex=1",
                    "-interaction=nonstopmode",
                    "-file-line-error",
                    "-pdf",
                    "-outdir=%OUTDIR%",
                    "%DOCFILE%"
                ]
            },
            {
                "name": "bibtex",
                "command": "bibtex",
                "args": [
                    "%DOCFILE%"
                ]
            }
        ],
        "latex-workshop.latex.recipes": [
            {
                "name": "XeLaTeX",
                "tools": [
                    "xelatex"
                ]
            },
            {
                "name": "PDFLaTeX",
                "tools": [
                    "pdflatex"
                ]
            },
            {
                "name": "BibTeX",
                "tools": [
                    "bibtex"
                ]
            },
            {
                "name": "LaTeXmk",
                "tools": [
                    "latexmk"
                ]
            },
            {
                "name": "xelatex -> bibtex -> xelatex*2",
                "tools": [
                    "xelatex",
                    "bibtex",
                    "xelatex",
                    "xelatex"
                ]
            },
            {
                "name": "pdflatex -> bibtex -> pdflatex*2",
                "tools": [
                    "pdflatex",
                    "bibtex",
                    "pdflatex",
                    "pdflatex"
                ]
            },
        ],
        "latex-workshop.latex.clean.fileTypes": [
            "*.aux",
            "*.bbl",
            "*.blg",
            "*.idx",
            "*.ind",
            "*.lof",
            "*.lot",
            "*.out",
            "*.toc",
            "*.acn",
            "*.acr",
            "*.alg",
            "*.glg",
            "*.glo",
            "*.gls",
            "*.ist",
            "*.fls",
            "*.log",
            "*.fdb_latexmk"
        ],
        "latex-workshop.latex.autoClean.run": "onFailed",
        "latex-workshop.latex.recipe.default": "lastUsed",
        "latex-workshop.view.pdf.internal.synctex.keybinding": "double-click"
```

