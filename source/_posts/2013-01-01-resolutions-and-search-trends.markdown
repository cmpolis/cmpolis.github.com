---
layout: post
title: "Resolutions and Search Trends"
date: 2013-01-01 15:26
comments: true
categories: 
---
Every new year, people make resolutions to better themselves. It's great that people use the holiday as a catalyst, but it seems like most resolutions are not very long lived, *e.g. the gym is always more crowded in Jan than June.* 

I thought it would be interesting to see this phenomenon in a less anecdotal light. I started messing with [Google Trends](http://www.google.com/trends/) and found the data to be as I suspected: huge spikes for most *new-years-resolutiony* terms. It was also interesting to see how similar the trends were for some terms were year over year.

I also compared the search traffic for each term in January with the year round search traffic for that term. The term that I found with the largest *Jan vs rest of year* average traffic difference was **'get organized'** with 1.52 times more search traffic in January.

I graphed the search trends of some *new-years-resolutiony* terms with [d3.js](http://d3js.org/):

*Mouseover a label to highlight a specific term*
<div id="labels"></div>
<div id="graph"></div>
<small>
[Raw data](https://docs.google.com/spreadsheet/pub?key=0AjB3CQ60Cfb4dHFhVGtXRmV0anB6R1o1TURJYTM2RlE&output=html), collected via [Google Trends](http://www.google.com/trends/). 
</small>

*All the best in 2013!*


<script src="http://d3js.org/d3.v3.js"></script>
<script>
var margin = {top: 20, right: 80, bottom: 30, left: 50},
    width = 720 - margin.left;// - margin.right,
    height = 500 - margin.top - margin.bottom;

var parseDate = d3.time.format("%x").parse;

var x = d3.time.scale()
    .range([0, width]);

var y = d3.scale.linear()
    .range([height, 0]);

var color = d3.scale.category10();

var xAxis = d3.svg.axis()
    .scale(x)
    .ticks(d3.time.years, 1)
    .orient("bottom");

var yAxis = d3.svg.axis()
    .scale(y)
    .orient("left");

var line = d3.svg.line()
    .interpolate("basis")
    .x(function(d) { return x(d.date); })
    .y(function(d) { return y(d.temperature); });

var svg = d3.select("#graph").append("svg")
    .attr("width", width + margin.left + margin.right)
    .attr("height", height + margin.top + margin.bottom)
  .append("g")
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");

d3.csv("/resolution_graph_data.csv", function(error, data) {
  color.domain(d3.keys(data[0]).filter(function(key) { return key !== "Week"; }));

  data.forEach(function(d) {
    d.date = parseDate(d.Week);
  });

  window.cities = color.domain().map(function(name, ndx) {
    return {
      name: name,
      values: data.map(function(d) {
        return {date: d.date, temperature: +d[name]};
      }),
      color: color(ndx)
    };
  });

  x.domain(d3.extent(data, function(d) { return d.date; }));

  y.domain([
    d3.min(cities, function(c) { return d3.min(c.values, function(v) { return v.temperature; }); }),
    d3.max(cities, function(c) { return d3.max(c.values, function(v) { return v.temperature; }); })
  ]);

  svg.append("g")
      .attr("class", "x axis")
      .attr("transform", "translate(0," + height + ")")
      .call(xAxis.tickSize(-height,0,0));

  svg.append("g")
      .attr("class", "y axis")
      .call(yAxis)
   // .append("text")
   //   .attr("transform", "rotate(-90)")
   //   .attr("y", 6)
   //   .attr("dy", ".71em")
   //   .style("text-anchor", "end")
   //   .text("Temperature (ºF)");

  var city = svg.selectAll(".city")
      .data(cities)
    .enter().append("g")
      .attr("class", "city");

  city.append("path")
      .attr("class", "line")
      .attr("id", function(d) { return d.name.replace(/\s/g,''); })
      .attr("d", function(d) { return line(d.values); })
      .style("stroke", function(d) { return color(d.name); });

  //city.append("text")
  //    .datum(function(d) { return {name: d.name, value: d.values[d.values.length - 1]}; })
  //    .attr("transform", function(d) { return "translate(" + x(d.value.date) + "," + y(d.value.temperature) + ")"; })
  //    .attr("x", 3)
  //    .attr("dy", ".35em")
  //    .text(function(d) { return d.name; });
var labels = d3.select("#labels").append('ul')
             .selectAll('li').data(cities).enter()
             .append('li')
             .attr('class', 'color-label')
             .text(function(d) { return d.name; })
             .style('color', function(d) { return d.color; })
             .on('mouseover', function(d) { 
               d3.select('#'+d.name.replace(/\s/g,''))
                 .style('stroke-opacity', '1');
             })
             .on('mouseout', function(d) { 
               d3.select('#'+d.name.replace(/\s/g,''))
                 .style('stroke-opacity', '.15');
             });
              
});
</script>
