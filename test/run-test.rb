#!/usr/bin/env ruby

require "test-unit"
require "test/unit/notify"
require "test/unit/rr"

base_dir = File.expand_path(File.join(File.dirname(__FILE__), ".."))
$LOAD_PATH.unshift(File.join(base_dir, "lib"))
$LOAD_PATH.unshift(File.join(base_dir, "test"))

ext_dir = File.join(base_dir, "ext")
ext_osl_dir = File.join(ext_dir, "osl")
$LOAD_PATH.unshift(ext_osl_dir)
require "fileutils"
FileUtils.cd(ext_osl_dir) do
  system("ruby", "extconf.rb")
  system("make")
end

exit Test::Unit::AutoRunner.run(true)
