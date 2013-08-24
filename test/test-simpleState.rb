require "osl"
require "stringio"

class SimpleStateTest < Test::Unit::TestCase
  def setup
    @sstate = Osl::State::SimpleState.new
  end

  def test_new
    assert_not_nil(Osl::State::SimpleState.new)
  end

  def test_show
    assert_true(@sstate.respond_to?(:show))
  end
end
