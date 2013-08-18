class OslTest < Test::Unit::TestCase
  def test_require_osl
    assert_nothing_raised do
      require "osl"
    end
  end
end
