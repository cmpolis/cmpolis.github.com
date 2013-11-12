---
layout: post
title: "Easy Scrolling Pages with scrollIt.js"
date: 2013-07-07 14:25
comments: true
categories: 
---
One web UI trend that has been growing in popularity recently is to display content on long scrolling pages (as opposed to using tabs or paginating content). I love going through UIs that scroll, <a href='http://rdio.com'>Rdio</a> comes to mind as a good example. I've also seen a lot of newer landing pages that are laid out with vertical scrolling. 

#### I &hearts; this trend; it allows for a much better user experience:

**Content can be teased**<br />
With content layed out vertically and depending on heights, you will probably be able to tease the next section and keep the user engaged. 
<p class='center'>{% img http://bytemuse.com/images/scrollvstab.png 540 321 Scrolling vs Tabs %}</p>

**Scrolling is much easier than clicking**<br />
I find it much easier to scroll*(especially since I'm almost always on a laptop with multi touch scrolling or a mouse with a scroll wheel)*. Making the page easier to navigate should get users to expose more content. 

**No additional page loads**<br />
Again, this kind of layout reduces friction for users to view content. Making a user wait for a page to load is unnecessary and inconvenient - just load everything at once when it makes sense. Bundling content is also likely to save server resources by reducing the number of requests, reloading assets, etc... 

<hr />

## The plugin - scrollIt.js
I've built a few sites with this layout. I have a general rule to not rewrite the same functionality three times - abstract it out and DRY it up. I wrote a jQuery plugin to use for future projects like this. It's really simple to use, lightweight, configurable and is open source!

It's as easy as putting `data-` attributes on DIVs and calling `$.scrollIt();`

<a href='https://github.com/cmpolis/scrollIt.js'><h1 class='center'>Get scrollIt.js on Github!</h1></a>
<a href='http://bytemuse.com/scrollIt.js'><h1 class='center'>Demo</h1></a>
