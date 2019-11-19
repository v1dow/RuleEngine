RuleEngine is a software that processes configuration files include rule, para, token and data.

All those configuration files should be provided by user, and should be added according to the specification below.



## `para.txt`

All strings that satisfy the following regular expression will be recognized as paras.

```c
[a-zA-Z_][a-zA-Z0-9_.]*
```

Different paras should be separated by line breaks.



## `rule.txt`

```bash
[rulename1]:IF LHS THEN RHS
[rulename2]:IF LHS THEN RHS
			...
```

LHS(left hand side) and RHS(right hand side) should be expressions contains paras and keyword defined by RuleEngine.

Different rules should be separated by line breaks.

Keywords supported by RuleEngine:

```c++
enum yytokentype
  {
    AND = 258,
    OR = 259,
    MORE = 260,
    LESS = 261,
    MEQL = 262,
    LEQL = 263,
    EQL = 264,
    NOTEQL = 265,
    BING = 266,
    LIAN = 267,
    UMINUS = 268,
    NOT = 269,
    NUMBER = 270,
    LISTNUMBER = 271,
    ID = 272,
    STRID = 273,
    LID = 274,
    STRING = 275,
    ADDRESS = 276,
    IF = 277,
    LOG = 278,
    SIN = 279,
    ASIN = 280,
    COS = 281,
    ACOS = 282,
    TAN = 283,
    ATAN = 284,
    STRIN = 285,
    EXP = 286,
    POW = 287,
    SQR = 288,
    MAX = 289,
    MIN = 290,
    MAXS = 291,
    MEAN = 292,
    EMPTY = 293
  };
```



## `data.txt`

Data should be separated by space.