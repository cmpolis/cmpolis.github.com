---
layout: post
title: "A Straightforward Cloud Computing Price Comparison"
date: 2013-06-26 23:21
comments: true
categories: 
---
*tl;dr: I made a sortable and filterable table of different cloud computing plans that adds transparency for comparing different plans and providers. [Available here.](http://CloudPriceGrid.com "Cloud Price Grid")*

There are a plethora of cloud hosting providers out there these days. For most of my recent projects, I have gone with Amazon EC2 without considering other solutions. However, there are two newer services that I have been wanting to try out - Digital Ocean and Google Compute Engine. 

I recently read about Digital Ocean and am enticed by their low prices as well as their advertised speed and ease of deployment. Google has recently launched their Compute Engine service, which directly competes with Amazon's EC2. 

After a bit of digging, I found there was no single place where I could compare all these services. Also, some providers*(eg. Amazon)* do not have a transparent pricing grid that covers their plans. What I wanted (and built) was a spreadsheet with all the plans from a few providers that contained basic plan information and could be sorted and filtered.

Unfortunately, a lot of plan metrics are either subjective or cannot be collected without benchmarking; cpu power, connectivity and stability could not be put on the grid. However, RAM, storage and price are fairly objective and given by each provider. Computing power for each plan is listed, but it is hard to compare between providers. I included an aggregate column of RAM per $ per month to give an indication of relative pricing.

Some quick observations:

- Amazon and Google have VERY comparable pricing.
- Joyent seems to be the least value (in terms of RAM/$/Month - maybe they have a value prop in another way)
- Digital Ocean has the best value (in terms of RAM/$/Month)

### Here it is: [CloudPriceGrid.com](http://CloudPriceGrid.com "Cloud Price Grid")
