# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'osl/version'

Gem::Specification.new do |spec|
  spec.name          = "osl"
  spec.version       = Osl::VERSION
  spec.authors       = ["Masafumi Yokoyama"]
  spec.email         = ["myokoym@gmail.com"]
  spec.description   = %q{Ruby/OSL is a Ruby binding of OpenShogiLib.}
  spec.summary       = %q{Ruby/OSL is a Ruby binding of OpenShogiLib.}
  spec.homepage      = "https://github.com/myokoym/ruby-osl"
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) {|f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.extensions    = ["ext/osl/extconf.rb"]
  spec.require_paths = ["lib", "ext/osl"]

  spec.add_development_dependency("test-unit")
  spec.add_development_dependency("test-unit-notify")
  spec.add_development_dependency("test-unit-rr")
  spec.add_development_dependency("bundler", "~> 1.3")
  spec.add_development_dependency("rake")
end
