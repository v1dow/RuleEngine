## `para.txt`

All strings that satisfy the following regular expression will be recognized as paras.

```c
[a-zA-Z_$#][a-zA-Z0-9_.$#]*
```

Different paras should be separated by line breaks.



## `rule.txt`

```bash
[rulename1]:IF LHS THEN RHS
[rulename2]:IF LHS THEN RHS
			...
```

LHS(left hand side) and RHS(right hand side) should be expressions contains paras(list data) and keyword defined by RuleEngine.

Different rules should be separated by line breaks.