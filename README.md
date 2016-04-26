Diskfree
========

Get a status report in [Backdrop](https://backdropcms.org/)'s status report and
a cron-triggered e-mail warning when locally mounted disk space on your Backdrop
server reaches a preset threshold.

The alert e-mail uses the following template:

> Alert: {hostname} is {percent}% full

> Running out of space {mount} ({percent}% used, {space} avail)
> on {hostname} for {site_name}

Requires df, grep, and awk to be in the global server $PATH available for PHP to
use.

Built for and tested with Debian, Ubuntu 12.04, Ubuntu 14.04, and Mac OSX.
Diskfree does not work reliably on Ubuntu 8.04. Most Linux-style environments
should work, but only the aforementioned are officially supported.

Diskfree is a component of the classic CIA information security triad:
confidentiality, integrity and availability. A full disk partition can halt a
web server and cause data corruption. From Wikipedia:

> For any information system to serve its purpose, the information must be
> available when it is needed. This means that the computing systems used to
> store and process the information, the security controls used to protect it,
> and the communication channels used to access it must be functioning
> correctly. High availability systems aim to remain available at all times,
> preventing service disruptions due to power outages, hardware failures, and
> system upgrades.

If you prefer, you could also just copy a
[bash script](https://gist.github.com/deekayen/3138161) in your `/usr/local/bin`
and install a crontab to do the same thing, except that it would only alert by
email.

Current Maintainer
------------------

- David Norman (https://github.com/deekayen)

Credits
-----------

- Originally written for Drupal by David Norman with funding from projects
  at Classic Graphics (https://www.knowclassic.com)
- Misc updates provided in Drupal by Chris Yu (https://www.drupal.org/u/cyu),
  Mark Shropshire (https://github.com/shrop),
  Brent Dunn (https://www.drupal.org/u/bdone),
  and Jeremy Edgell (https://www.drupal.org/u/jeremyclassic)
- Ported to Backdrop by David Norman (https://github.com/deekayen)

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
