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

  def test_pieceAt
    piece = @sstate.pieceAt("77")
    assert_true(piece.is_a?(Osl::Piece))
  end

  def test_at
    piece = @sstate.at("77")
    assert_true(piece.is_a?(Osl::Piece))
  end
end
