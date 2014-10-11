cjson_sample API
======

This is an example using [cJSON](https://github.com/kbranigan/cJSON) to proccess [JSON](http://json.org) data.
The API consists of 3 elements:

* package (holds the package.json data)
* getProperty (used to fetch data)
* setProperty (used to update properties)

Both functions are overloaded and provide the following options:
## getProperty
| Parameters                    | Returns                  |
| -------------                 | -------------            |
| string cat                    | vector of cJSON* objects |
| string cat, string property   | single cJSON* object     |

## setProperty
| Parameters                                  | Updates                                 |
| -------------                               | -------------                           |
| string cat, string property, value          | single property on a subcategory        |
| string cat, string property, vector<cJSON*> | list of cJSON* objects on a subcategory |
| string cat, vector<cJSON*>                  | list of cJSON* objects on a category    |
| string cat, cJSON*                          | single property on a category           |
