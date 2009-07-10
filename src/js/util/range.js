// vim:ts=2:sw=2:expandtab:autoindent:
/*
The MIT License

Copyright (c) 2008, 2009 Aristid Breitkreuz, Ash Berlin, Ruediger Sonderfeld

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

var Util = exports;

/**
 * Create an iterable object returning all objects in a range, starting
 * at "from", up to (not including) "to", incrementing by "by" in each step.
 *
 * @param {number} from The start of the range.
 * @param {number} to The (non-inclusive) end of the range.
 * @param {number} by The increment. Default: 1.
 *
 * @class
 */
Util.Range = function Util$Range(from, to, by) {
  // TODO: find out why this hack is needed / how to get rid of it
  var fun = new Function(
    'from', 'to', 'by',
    'var i = from; by = by || 1; while (i < to) { yield i; i += by; }');
  return fun(from, to, by);
}
