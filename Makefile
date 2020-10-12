
default:	build

clean:
	rm -rf Makefile objs

build:
	$(MAKE) -f objs/Makefile

install:
	$(MAKE) -f objs/Makefile install

modules:
	$(MAKE) -f objs/Makefile modules

upgrade:
	/Users/huoyinghui/github/nginx/sbin/nginx -t

	kill -USR2 `cat /Users/huoyinghui/github/nginx/logs/nginx.pid`
	sleep 1
	test -f /Users/huoyinghui/github/nginx/logs/nginx.pid.oldbin

	kill -QUIT `cat /Users/huoyinghui/github/nginx/logs/nginx.pid.oldbin`
