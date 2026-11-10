### move

[モジュールへ戻る][back]

テンプレート：

`typename T`

引数

`T&& arg`

戻り値

`constexpr typename remove_ref<T>::type&&`

argを右辺値参照に静的キャストします。

左辺値でも右辺値でも移動できるよう、argはユニバーサル参照です。

[モジュールへ戻る][back]

[back]: index.md