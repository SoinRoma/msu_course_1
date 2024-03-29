# [Сортировка Слиянием](https://github.com/SoinRoma/MSU_1Course/tree/master/sorting/merge_sort)

Подробный алгоритм сортировки:
+ Сортируемый массив разбивается на две части примерно одинакового размера;
+ Каждая из получившихся частей сортируется отдельно, например — тем же самым алгоритмом;
+ Два упорядоченных массива половинного размера соединяются в один.
+ Рекурсивное разбиение задачи на меньшие происходит до тех пор, пока размер массива не достигнет единицы (любой массив длины 1 можно считать упорядоченным).
+ Соединение двух упорядоченных массивов в один.

Пусть мы имеем два уже отсортированных по возрастанию подмассива. Тогда:
+ Слияние двух подмассивов в третий результирующий массив.
+ На каждом шаге мы берём меньший из двух первых элементов подмассивов и записываем его в результирующий массив. 
+ Счётчики номеров элементов результирующего массива и подмассива, из которого был взят элемент, увеличиваем на 1.
+ «Прицепление» остатка.
+ Когда один из подмассивов закончился, мы добавляем все оставшиеся элементы второго подмассива в результирующий массив.

# [Сортировка Бинарным поиском](https://github.com/SoinRoma/MSU_1Course/tree/master/sorting/binary_search_sort)

Подробный алгоритм сортировки:
+ Определение значения элемента в середине структуры данных. Полученное значение сравнивается с ключом.
+ Если ключ меньше значения середины, то поиск осуществляется в первой половине элементов, иначе — во второй.
+ Поиск сводится к тому, что вновь определяется значение серединного элемента в выбранной половине и сравнивается с ключом.
+ Процесс продолжается до тех пор, пока не будет найден элемент со значением ключа или не станет пустым интервал для поиска.