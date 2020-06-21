import urllib.request
import gevent
from gevent import monkey

"""
def main():
    req = urllib.request.urlopen("http://pic.netbian.com/uploads/allimg/200524/000812-1590336492bd6b.jpg")
    img_content = req.read()
    with open("蒂法手机壁纸.jpg", "wb") as f:
        f.write(img_content)


if __name__ == '__main__':
    main()
"""
monkey.patch_all()


def my_download(img_name, img_url):
    req = urllib.request.urlopen(img_url)
    img_content = req.read()
    with open(img_name, "wb") as f:
        f.write(img_content)


def main():
    gevent.joinall([
        gevent.spawn(my_download, '刘亦菲1.jpg', 'http://pic.netbian.com/uploads/allimg/200524/234208-1590334928917b.jpg'),
        gevent.spawn(my_download, '锐雯1.jpg', 'http://pic.netbian.com/uploads/allimg/200524/002940-15902513809951.jpg'),
        gevent.spawn(my_download, 'SurfaceBook3.jpg', 'http://pic.netbian.com/uploads/allimg/200518/212713-15898084333e1e.jpg')
    ])


if __name__ == '__main__':
    main()
