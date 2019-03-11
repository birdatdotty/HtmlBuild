Приложение для простого создания сайта на HTML.
Программа не для сервера, а для компьютера разработчика
Следуще директории нужны для правильной работы программы (чтение и запись):
* /var/www/html (для записи готовых страниц)
* /var/www/html/css (необезательно, но файл стилей прописан там)
* /var/www/html/img (используется для всех картинок сайта)
* /var/lib/htmlbuild (для записи настроек модулей и сайта)


Сборка проверялась для linux и windows, но опишу только для linux (это основная моя система):
# получения и сборка проекта:
git clone https://github.com/birdatdotty/HtmlBuild.git
cd HtmlBuild
mkdir build
cd build
qmake ..
make

# Подготовка системы для работы программы
sudo mkdir /var/lib/htmlbuild
sudo chmod -R 777 /var/lib/htmlbuild /var/www/html
cp htmlbuild/config.json /var/lib/htmlbuild
./HtmlBuild
