---
layout: post
title: "Obligatory First Post"
date: 2012-12-30 22:09
comments: true
categories: 
---
After a hiatus of about a year, I've decided to blog again! I'm not one for making resolutions, but in 2013 and beyond, I plan to write more and do more open source coding. I blogged previously on ByteMuse.com and had a handful of posts, but I'm hoping to start posting more regularly. 

Some topics that I want to cover are:

- Open Source
- Web Development
- Mobile Development
- Databases
- Travel
- Books, Music, Movies

### Old Posts
I've decided not to migrate my old posts for various reasons. Many of these posts are complemented with code that is still available on my [GitHub Account](http://github.com/cmpolis). 

### Setup
*If you're into web development, you might find this interesting...*

I previously ran my blog with WordPress and hated it: the templating and plugin system are really heavy, it favors editing and customization through UI instead of code... and it's written in PHP.

My new blog is powered by [Octopress](http://octopress.org) and so far it has been great! Octopress is a ruby based static site generator that uses a simple templating system. I am using markdown for blog posts, HAML and HTML for static pages and SASS for styling. For comments, I am using Disqus since it can be added with a simple embed.

To deploy, I simply run a rake command to generate my site as static content and assets, then push it to GitHub. I don't have to worry about databases, bandwidth or management. Easy. 
